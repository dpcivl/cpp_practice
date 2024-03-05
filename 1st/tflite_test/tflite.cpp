#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/model.h"
#include <iostream>


int main() {
    // 모델 파일 경로
    const char* model_path = "model/TestModel.tflite";

    // 모델 로드
    std::unique_ptr<tflite::FlatBufferModel> model = tflite::FlatBufferModel::BuildFromFile(model_path);
    if (!model) {
        std::cerr << "Failed to load model" << std::endl;
        return 1;
    }
    std::cout << "Model loaded successfully" << std::endl;

    // 인터프리터 생성
    std::unique_ptr<tflite::Interpreter> interpreter;
    tflite::InterpreterBuilder(*model, tflite::ops::builtin::BuiltinOpResolver())(&interpreter);
    if (!interpreter) {
        std::cerr << "Failed to create interpreter" << std::endl;
        return 1;
    }
    std::cout << "Interpreter created successfully" << std::endl;

    return 0;
}
