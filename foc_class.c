#include <stdio.h>
#include <math.h>

typedef struct {
    int pole_pairs;          // 极对数
    float rated_voltage;     // 额定电压
    float rated_current;     // 额定电流
} MotorParameters;

typedef struct {
    float current_alpha;     // alpha电流分量
    float current_beta;      // beta电流分量
    float current_d;         // d轴电流
    float current_q;         // q轴电流
    float rotor_angle;       // 转子角度
} FOCController;

void update_currents(FOCController* controller, float alpha, float beta) {
    controller->current_alpha = alpha;
    controller->current_beta = beta;
}

void update_rotor_angle(FOCController* controller, float angle) {
    controller->rotor_angle = angle;
}

void calculate_dq_currents(FOCController* controller) {
    // 根据alpha和beta电流计算d轴和q轴电流
    controller->current_d = controller->current_alpha * cosf(controller->rotor_angle) + controller->current_beta * sinf(controller->rotor_angle);
    controller->current_q = -controller->current_alpha * sinf(controller->rotor_angle) + controller->current_beta * cosf(controller->rotor_angle);
}

void calculate_voltage_vector(FOCController* controller) {
    // 根据d轴和q轴电流计算电压矢量
    // 这里可以根据具体的控制策略来实现FOC算法
}

void control_motor(FOCController* controller) {
    // 控制电机运行
    calculate_dq_currents(controller);
    calculate_voltage_vector(controller);
    // 根据电压矢量控制电机运行
}

int main() {
    // 创建FOC控制器对象
    MotorParameters motor_parameters = {
        .pole_pairs = 4,             // 极对数
        .rated_voltage = 24.0,       // 额定电压
        .rated_current = 5.0         // 额定电流
    };
    FOCController foc_controller = {
        .current_alpha = 0.0,        // alpha电流分量
        .current_beta = 0.0,         // beta电流分量
        .current_d = 0.0,            // d轴电流
        .current_q = 0.0,            // q轴电流
        .rotor_angle = 0.0           // 转子角度
    };

    // 更新电流和角度
    float alpha = 1.0;               // alpha电流分量
    float beta = 2.0;                // beta电流分量
    float angle = M_PI / 4;          // 角度
    update_currents(&foc_controller, alpha, beta);
    update_rotor_angle(&foc_controller, angle);

    // 控制电机运行
    control_motor(&foc_controller);

    return 0;
}