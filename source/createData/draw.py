import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# hàm vẽ biểu đồ cột
def draw(data, title, xlabel, ylabel, filename):
    plt.figure(figsize=(10, 5))
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.plot(data)
    plt.savefig(filename)
    plt.close()

# hàm vẽ biểu đồ đường
def draw_bar(data, title, xlabel, ylabel, filename):
    plt.figure(figsize=(10, 5))
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.bar(data.index, data.values)
    plt.savefig(filename)
    plt.close()

