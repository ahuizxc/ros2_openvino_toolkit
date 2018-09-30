/*
 * Copyright (c) 2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @brief A header file with declaration for HeadPoseDetectionModel Class
 * @file head_pose_detection_model.h
 */


#ifndef DYNAMIC_VINO_LIB__OUTPUTS__BASE_OUTPUT_HPP_
#define DYNAMIC_VINO_LIB__OUTPUTS__BASE_OUTPUT_HPP_

#include <string>
#include <vector>

#include "dynamic_vino_lib/inferences/base_inference.hpp"
#include "dynamic_vino_lib/inferences/emotions_detection.hpp"
#include "dynamic_vino_lib/inferences/face_detection.hpp"
#include "dynamic_vino_lib/inferences/age_gender_detection.hpp"
#include "dynamic_vino_lib/inferences/head_pose_detection.hpp"
#include "opencv2/opencv.hpp"

namespace Outputs {
/**
 * @class BaseOutput
 * @brief This class is a base class for various output devices. It employs
 * visitor pattern to perform different operations to different inference
 * result with different output device
 */
class BaseOutput {
 public:
  BaseOutput() = default;
  /**
   * @brief Generate output content according to the face detection result.
   */
  virtual void accept(const std::vector<dynamic_vino_lib::FaceDetectionResult>&){}
  /**
   * @brief Generate output content according to the emotion detection result.
   */
  virtual void accept(const std::vector<dynamic_vino_lib::EmotionsResult>&){}
  /**
   * @brief Generate output content according to the age and gender detection result.
   */
  virtual void accept(const std::vector<dynamic_vino_lib::AgeGenderResult>&){}
  /**
   * @brief Generate output content according to the headpose detection result.
   */
  virtual void accept(const std::vector<dynamic_vino_lib::HeadPoseResult>&){}
  /**
   * @brief Calculate the camera matrix of a frame for image window output, no
   	 implementation for ros topic output.
   */
  virtual void feedFrame(const cv::Mat& frame) {}
  /**
   * @brief Show all the contents generated by the accept functions.
   */
  virtual void handleOutput(const std::string& overall_output_text, 
    const std::string& input_type) = 0;
  /**
   * @brief Calculate real time FPS (frames per second).
   */
  int getFPS() const;
};
}  // namespace Outputs
#endif  // DYNAMIC_VINO_LIB__OUTPUTS__BASE_OUTPUT_HPP_
