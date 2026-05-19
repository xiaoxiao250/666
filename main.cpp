#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <random>
#include <string>

using namespace ftxui;

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    const int target = dis(gen);

    std::string input;
    std::string message = "欢迎来到猜数字游戏！输入 1-100 的数字开始~";
    bool game_over = false;

    auto screen = ScreenInteractive::TerminalOutput();

    // 输入框和按钮组件
    auto input_box = Input(&input, "请输入你的猜测");
    auto submit_btn = Button("提交答案", [&] {
        if (game_over) return;

        int guess;
        try {
            guess = std::stoi(input);
        } catch (...) {
            message = "❌ 请输入有效的数字！";
            input.clear();
            return;
        }

        if (guess < 1 || guess > 100) {
            message = "⚠️ 数字必须在 1-100 之间！";
        } else if (guess < target) {
            message = "⬆️ 太小啦！试试更大的数字~";
        } else if (guess > target) {
            message = "⬇️ 太大啦！试试更小的数字~";
        } else {
            message = "🎉 恭喜你猜对了！答案就是 " + std::to_string(target);
            game_over = true;
        }
        input.clear();
    });

    // 用 Renderer 把组件和界面元素分开，彻底解决类型错误
    auto layout = Container::Vertical({
        input_box,
        submit_btn
    });

    auto renderer = Renderer(layout, [&] {
        return vbox({
            text("🎮 猜数字游戏") | center | bold | color(Color::Blue),
            separator(),
            text(message) | center | color(Color::Yellow),
            separator(),
            input_box->Render(),
            submit_btn->Render() | center
        }) | border | size(HEIGHT, GREATER_THAN, 15);
    });

    screen.Loop(renderer);
    return 0;
}