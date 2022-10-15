import os

for i in ["1Kints.txt", "2Kints.txt", "4Kints.txt", "8Kints.txt",
        "16Kints.txt", "32Kints.txt"]:
    with open(i, "r") as file:
        text = file.read()
        text = text.replace(" ", "")
        file.close()

    os.system(f"rm ~/github/ufsc/algorithms/sums/three-sum-fast/{i}")
    os.system(f"touch {i}")
    with open(i, "w") as to_write:
        to_write.write(text)
        to_write.close()
