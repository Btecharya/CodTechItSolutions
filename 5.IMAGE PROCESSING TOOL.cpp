#include <opencv2/opencv.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

using namespace cv;

// Function to apply grayscale filter
void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

// Function to apply blur filter
void applyBlur(Mat& image) {
    blur(image, image, Size(10, 10));
}

// Function to apply sharpen filter
void applySharpen(Mat& image) {
    Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0,
                                       -1, 5, -1,
                                        0, -1, 0);
    filter2D(image, image, image.depth(), kernel);
}

// Function to adjust brightness and contrast
void adjustBrightnessContrast(Mat& image, double alpha, int beta) {
    image.convertTo(image, -1, alpha, beta);
}

int main() {
    // Initialize GLFW and OpenGL
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Image Processing Tool", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Load image
    Mat image = imread("example.jpg");
    Mat processedImage;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Display image
        if (!image.empty()) {
            ImGui::Image((void*)(intptr_t)image.data, ImVec2(image.cols, image.rows));
            if (ImGui::Button("Grayscale"))
                applyGrayscale(image);
            ImGui::SameLine();
            if (ImGui::Button("Blur"))
                applyBlur(image);
            ImGui::SameLine();
            if (ImGui::Button("Sharpen"))
                applySharpen(image);

            ImGui::SliderFloat("Brightness", &brightness, 0.0f, 3.0f);
            ImGui::SliderInt("Contrast", &contrast, -100, 100);
            if (ImGui::Button("Adjust Brightness/Contrast"))
                adjustBrightnessContrast(image, brightness, contrast);

            if (ImGui::Button("Save Image"))
                imwrite("processed_image.jpg", image);
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
