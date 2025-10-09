from setuptools import setup, Extension
from pybind11.setup_helpers import build_ext
import pybind11

ext_modules = [
    Extension(
        "purpchi",  # Python import 名称
        sources=[
            "py/purpchi_bind.cpp",
            "src/ziwei/arrangeChart.cpp",
        ],
        include_dirs=[
            pybind11.get_include(),
            "includes",
            "includes/ziwei",
            "includes/algorithms",
        ],
        language="c++",
        extra_compile_args=["-std=c++17"],
    ),
]

setup(
    name="purpchi",
    version="0.1",
    author="Minun",
    description="紫微斗数算法 Python 封装",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
