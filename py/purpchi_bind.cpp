// 文件: py/purpchi_bind.cpp
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // 如果有std::string, std::vector等参数
#include "includes/ziwei/arrangeChart.h"   // 包含对应函数声明

namespace py = pybind11;

// 假设 arrangeChart 有类似签名：
// std::map<std::string, std::string> arrangeChart(std::string birth, std::string gender);

PYBIND11_MODULE(purpchi, m) {
    m.doc() = "Purpchi: 紫微斗数核心算法 Python 接口";
    
    m.def(
        "arrange_chart",
        &arrangeChart,
        py::arg("birth"),
        py::arg("gender"),
        "根据出生时间与性别生成紫微斗数命盘"
    );
}
