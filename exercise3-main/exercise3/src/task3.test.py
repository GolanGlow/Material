#!/usr/bin/env python3

"""
This script generated plots from the data task3.test.cpp produces in output/

TODO:
  run command (ensure you have executed task3 before, i.e. the CSV files are present in ouput/):
  python src/task3.test.py
"""

import os
import unittest
import matplotlib.pyplot as plt
import task3


class Test(unittest.TestCase):
    def test_plot_sin(self):

        figname = "output/test.task3.sin.png"

        if os.path.isfile(figname):
            os.remove(figname)

        plt.close("all")
        task3.plot_discrete_function("output/test.task3.sin.csv", ";", figname)
        plt.close("all")

        self.assertTrue(os.path.isfile(figname))

    def test_plot_cos(self):

        figname = "output/test.task3.cos.png"

        if os.path.isfile(figname):
            os.remove(figname)

        plt.close("all")
        task3.plot_discrete_function("output/test.task3.cos.csv", ";", figname)
        plt.close("all")

        self.assertTrue(os.path.isfile(figname))


if __name__ == "__main__":
    unittest.main()
