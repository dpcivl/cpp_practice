#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/options.h"

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 모델 파일 경로
    const char* model_path = "./model/ssd_mobilenet_v2_coco_quant_postprocess.tflite";

    // TFLite 모델 로드
    std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile(model_path);
    if (!model) {
        std::cerr << "Failed to load model" << std::endl;
        return -1;
    }

    // 인터프리터 생성
    tflite::ops::builtin::BuiltinOpResolver resolver;
    std::unique_ptr<tflite::Interpreter> interpreter;
    tflite::InterpreterBuilder(*model, resolver)(&interpreter);
    if (!interpreter) {
        std::cerr << "Failed to create interpreter" << std::endl;
        return -1;
    }

    // 인터프리터 설정 및 할당
    interpreter->AllocateTensors();

    // 입력 및 출력 텐서 준비 (여기서는 첫 번째 입력 및 출력 텐서 사용)
    float* input_tensor = interpreter->typed_input_tensor<float>(0);
    // TFLite 모델에 입력 데이터 설정 예제...
    // 예를 들어, OpenCV로 캡처한 이미지 데이터를 전처리하여 input_tensor에 복사하는 코드 추가

    // 모델 실행
    if (interpreter->Invoke() != kTfLiteOk) {
        std::cerr << "Failed to invoke tflite!" << std::endl;
    }

    // 출력 텐서에서 결과 가져오기
    float* output_tensor = interpreter->typed_output_tensor<float>(0);
    // 결과 처리 예제...
    // 예를 들어, output_tensor에서 결과를 읽어와서 처리하는 코드 추가

    return 0;
}

