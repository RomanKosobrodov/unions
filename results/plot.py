import matplotlib.pyplot as plt
import numpy as np
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Plot results")
    parser.add_argument("filename",
                        type=str,
                        help="CSV file name")
    args = parser.parse_args()

    labels = np.genfromtxt(args.filename, delimiter=",", dtype=str, max_rows=1)
    data = np.genfromtxt(args.filename, delimiter=",", skip_header=1)
    data = data / 1000

    labels = [x.replace("\"", "") for x in labels]
    colors = ["#3A6D80", "#F3CD53", "#D56729", "#9D402D"]

    fig, ax = plt.subplots()
    bplot = ax.boxplot(data,
                       patch_artist=True,
                       tick_labels=labels,
                       medianprops={"color": "black"})

    for patch, color in zip(bplot['boxes'], colors):
        patch.set_facecolor(color)
    ax.set_ylabel("time, ms")

    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)

    plt.savefig("results.png", dpi=300)
    plt.show()

