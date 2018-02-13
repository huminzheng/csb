#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "Scene.h"
#include "MaterialPBR.h"
#include "MaterialPhong.h"
#include "ShaderLib.h"


class DemoScene : public Scene
{
  Q_OBJECT
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Constructor for DemoScene.
  /// @param [io] io_camera the camera used to view the scene.
  /// @param [io] io_parent the parent window to create the GL context in.
  //----------------------------------------------------------------------------------------------------------------------
  DemoScene(Camera* io_camera, ShaderLib* io_shaderLib, QWidget *_parent) :
    Scene(io_camera, _parent),
    m_shaderLib(io_shaderLib)
  {}
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default copy constructor.
  //-----------------------------------------------------------------------------------------------------
  DemoScene(const DemoScene&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default copy assignment operator.
  //-----------------------------------------------------------------------------------------------------
  DemoScene& operator=(const DemoScene&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default move constructor.
  //-----------------------------------------------------------------------------------------------------
  DemoScene(DemoScene&&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default move assignment operator.
  //-----------------------------------------------------------------------------------------------------
  DemoScene& operator=(DemoScene&&) = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Default destructor.
  //-----------------------------------------------------------------------------------------------------
  ~DemoScene() override = default;
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to intialise the scene, must call the base class init.
  //-----------------------------------------------------------------------------------------------------
  virtual void init() override;

public slots:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to allow rotation of the model to be toggled.
  /// @param [in] _rotating tells the scene whether it should rotate the model or not.
  //-----------------------------------------------------------------------------------------------------
  void rotating(const bool _rotating);
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to link a Qt button to the scene, to allow switching between meshes in the scene, this
  /// calls loadMesh.
  //-----------------------------------------------------------------------------------------------------
  void generateNewGeometry();

  void nextMaterial();

private:
  //-----------------------------------------------------------------------------------------------------
  /// @brief Used to load mesh data into our buffer.
  //-----------------------------------------------------------------------------------------------------
  void loadMesh();
  //-----------------------------------------------------------------------------------------------------
  /// @brief Must call the base class function, it then applies our shader and draws the current mesh.
  //-----------------------------------------------------------------------------------------------------
  virtual void renderScene() override;

private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Holds the index of the currently drawn mesh in our array of meshes.
  //----------------------------------------------------------------------------------------------------------------------
  size_t m_meshIndex = 0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Holds our test meshes.
  //----------------------------------------------------------------------------------------------------------------------
  std::array<Mesh, 5> m_meshes;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Holds our shader programs.
  //----------------------------------------------------------------------------------------------------------------------
  ShaderLib* m_shaderLib;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Holds our material settings for the shader.
  //----------------------------------------------------------------------------------------------------------------------
  using matPtr = std::unique_ptr<Material>;
  std::array<matPtr, 2> m_materials = {{
    matPtr{new MaterialPhong(m_camera)},
    matPtr{new MaterialPBR(m_camera)}
  }};
  size_t m_currentMaterial = 0;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Is the mesh rotating.
  //----------------------------------------------------------------------------------------------------------------------
  bool m_rotating;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Wraps up our openGL buffers and VAO.
  //----------------------------------------------------------------------------------------------------------------------
  Buffer m_buffer;

};

#endif // DEMOSCENE_H
