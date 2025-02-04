/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "TfLiteMicroArduino.h"
#include "sine_model_data.h"

float angle = 0;

void setup() {
  Serial.begin(9600);
  TfLiteMicro.begin(g_sine_model_data);
}

void loop() {
  if (TfLiteMicro.failed()) {
    Serial.print("TfLiteMicro error:");
    Serial.println(TfLiteMicro.error());
  }
  TfLiteMicro.inputFloat(0)[0] = angle;
  TfLiteMicro.invoke();
  Serial.println(TfLiteMicro.outputFloat(0)[0]);
  angle += 0.1f;
  if (angle > 2 * M_PI) {
    angle = 0.0f;
  }
}
