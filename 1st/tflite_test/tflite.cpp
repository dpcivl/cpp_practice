#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/kernels/register.h"

#include <iostream>

int main() {
    // 모델 파일 경로
    const char* model_path = "model.tflite";

    // 모델 로드
    std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile(model_path);
    if (!model) {
        std::cerr << "Failed to load model: " << model_path << std::endl;
        return 1;
    }
    std::cout << "Model loaded successfully." << std::endl;

    // 인터프리터 구성
    tflite::ops::builtin::BuiltinOpResolver resolver;
    std::unique_ptr<tflite::Interpreter> interpreter;
    tflite::InterpreterBuilder(*model, resolver)(&interpreter);
    if (!interpreter) {
        std::cerr << "Failed to create interpreter." << std::endl;
        return 1;
    }

    // 인터프리터 할당
    if (interpreter->AllocateTensors() != kTfLiteOk) {
        std::cerr << "Failed to allocate tensors." << std::endl;
        return 1;
    }

    // 여기에 모델 실행 코드 추가

    std::cout << "Minimal TensorFlow Lite C++ example completed." << std::endl;

    return 0;
}
