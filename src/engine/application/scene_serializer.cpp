// MIT License
// 
// Copyright (c) 2020 Jean-Louis Haywood
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "scene_serializer.hpp"
#include <yaml-cpp/yaml.h>
#include <string>
#include <set>
#include "scene/scene.hpp"
#include "scene/component_variant.hpp"
#include <os/os.hpp>

Lilliputian::SceneSerializer::SceneSerializer(std::string dataDirectory)
{
	this->dataDirectory = dataDirectory;
}

Lilliputian::Scene Lilliputian::SceneSerializer::loadFromFile(std::string filepath)
{
	Scene scene;

	if (true)
	{
		scene = this->loadFromTextFile(filepath);
	}

	return scene;

}

bool Lilliputian::SceneSerializer::doesSceneExist(std::string filepath)
{
	return OS::getFileAccess().exists(this->dataDirectory + filepath);
}

Lilliputian::Scene Lilliputian::SceneSerializer::loadFromTextFile(std::string filepath)
{
	Scene scene;
	const std::string fullFilepath = this->dataDirectory + filepath;

	try
	{
		YAML::Node yamlNode = YAML::LoadFile(fullFilepath);

		for (YAML::const_iterator it0 = yamlNode.begin(); it0 != yamlNode.end(); ++it0)
		{
			if (it0->first.as<std::string>() == "Scene")
			{
				for (YAML::const_iterator it1 = it0->second.begin(); it1 != it0->second.end(); ++it1)
				{
					if (it1->first.as<std::string>() == "Entity")
					{
						Entity entity;
						scene.addEntity(entity);

						for (YAML::const_iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
						{
							ComponentVariant componentVariant;

							//Entity attributes
							if (it2->first.as<std::string>() == "name")
							{
								scene.getLastEntity().name = it2->second.as<std::string>();
							}
							else if (it2->first.as<std::string>() == "spatial_dimension")
							{
								int value = it2->second.as<int>();

								if (value == 2)
									scene.getLastEntity().spatialDimension = Entity::SpatialDimension::_2D;
							}
							else if (it2->first.as<std::string>() == "parent")
							{
								scene.getLastEntity().parentID = scene.getEntityByName(it2->second.as<std::string>()).ID;
							}
							//Components
							else if (it2->first.as<std::string>() == "BehaviourTree")
							{
								BehaviourTree* aiBehaviourTree = new BehaviourTree();

								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}

								componentVariant.setTo(aiBehaviourTree);
								scene.addComponentToLastEntity(componentVariant);
							}
							else if (it2->first.as<std::string>() == "SightPerception")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "AnimatedSprite")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "AudioListener")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "AudioStreamSource")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "Camera")
							{
								Camera* camera = new Camera();

								camera->setViewportHeight(480);
								camera->setIsStreaming(true);

								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "viewport_px")
									{
										camera->setViewportHeight(it3->second[1].as<double>());
										camera->setViewportWidth(it3->second[0].as<double>());
									}
									else if (it3->first.as<std::string>() == "limits_px")
									{
										camera->setLimits(
											it3->second[0].as<double>(),
											it3->second[1].as<double>(),
											it3->second[2].as<double>(),
											it3->second[3].as<double>()
										);
									}
									else if (it3->first.as<std::string>() == "keepAspect")
									{
										camera->setKeepAspect(it3->second.as<bool>());
									}
									else if (it3->first.as<std::string>() == "isStreaming")
									{
										camera->setIsStreaming(it3->second.as<bool>());
									}
								}

								componentVariant.setTo(camera);
								scene.addComponentToLastEntity(componentVariant);
							}
							else if (it2->first.as<std::string>() == "BallCollider")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "ConstantDirectionalForce")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "ConstantPointForce")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "CountdownTimer")
							{

								CountdownTimer* countdownTimer = new CountdownTimer();

								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "")
									{

									}
								}

								componentVariant.setTo(countdownTimer);
								scene.addComponentToLastEntity(componentVariant);
							}
							else if (it2->first.as<std::string>() == "NavigationMeshAgent")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "NavigationMeshBoxObstacle")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "NavigationPath")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "PhysicsConstraint")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "PhysicsThruster")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "PropertyAnimation")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "BoxCollider")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "BoxMesh")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "BoxTriggerSpace")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "RegularPolytopalMesh")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "RigidBody")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "Sprite")
							{
								Sprite* sprite = new Sprite();

								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "image")
									{
										Image image = scene.getAssetCache().loadImage((this->dataDirectory + it3->second.as<std::string>()).c_str());
										sprite->setImage(image);
									}
								}

								componentVariant.setTo(sprite);
								scene.addComponentToLastEntity(componentVariant);
							}
							else if (it2->first.as<std::string>() == "StaticFluid")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "Transform")
							{
								Transform* transform = new Transform();

								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "translation")
									{
										transform->translation.x = it3->second[0].as<double>();
										transform->translation.y = it3->second[1].as<double>();
										transform->translation.z = it3->second[2].as<double>();
									}
									else if (it3->first.as<std::string>() == "rotation")
									{
										transform->rotation.x = it3->second[0].as<double>();
										transform->rotation.y = it3->second[1].as<double>();
										transform->rotation.z = it3->second[2].as<double>();
									}
									else if (it3->first.as<std::string>() == "scale")
									{
										transform->scale.x = it3->second[0].as<double>();
										transform->scale.y = it3->second[1].as<double>();
										transform->scale.z = it3->second[2].as<double>();
									}
								}

								componentVariant.setTo(transform);
								scene.addComponentToLastEntity(componentVariant);
							}
							else if (it2->first.as<std::string>() == "UIButton")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIGraphEdit")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIGraphNode")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIScrollbar")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UISeparator")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UISlider")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIHoverCard")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIItemList")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIPanel")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIProgressBar")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIRectangle")
							{
							for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
							{
								if (it3->first.as<std::string>() == "default")
								{

								}
								else if (it3->first.as<std::string>() == "")
								{

								}
							}
							}
							else if (it2->first.as<std::string>() == "UISpinBox")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UITab")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UITextEdit")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UITextLabel")
							{
								UITextLabel* uiTextLabel = new UITextLabel();

								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "text")
									{
										uiTextLabel->setText(it3->second.as<std::string>());
									}
									else if (it3->first.as<std::string>() == "font")
									{
										Font font = scene.getAssetCache().loadFont((
											this->dataDirectory + it3->second[0].as<std::string>()).c_str(),
											it3->second[1].as<int>());

										uiTextLabel->setFont(font, it3->second[1].as<int>());
									}
									else if (it3->first.as<std::string>() == "colour")
									{
										uiTextLabel->setColour(
											it3->second[0].as<int>(),
											it3->second[1].as<int>(),
											it3->second[2].as<int>(),
											it3->second[3].as<int>()
										);
									}
								}

								componentVariant.setTo(uiTextLabel);
								scene.addComponentToLastEntity(componentVariant);
							}
							else if (it2->first.as<std::string>() == "UITree")
							{
								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "default")
									{

									}
									else if (it3->first.as<std::string>() == "")
									{

									}
								}
							}
							else if (it2->first.as<std::string>() == "UIViewport")
							{
								UIViewport* uiViewport = new UIViewport();

								for (YAML::const_iterator it3 = it2->second.begin(); it3 != it2->second.end(); ++it3)
								{
									if (it3->first.as<std::string>() == "camera_entity")
									{
										uiViewport->setCameraEntity(scene.getEntityByName(it3->second.as<std::string>()).ID);
									}
								}

								componentVariant.setTo(uiViewport);
								scene.addComponentToLastEntity(componentVariant);
							}
							/*Non-components*/
							else if (it2->first.as<std::string>() == "Scripts")
							{
								for (int i = 0; i < it2->second.size(); i++)
								{
									std::string script = it2->second[i].as<std::string>();
									scene.getLastEntity().scripts.push_back(script);
								}
							}
						}
					}
				}
			}
		}
	}
	catch (int e)
	{

	}

	return scene;
}