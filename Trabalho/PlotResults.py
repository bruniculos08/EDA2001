import matplotlib.pyplot as plt
import numpy as np

# (1) Caminho da pasta do trabalho:
generalPath = "C:\\Users\\bruni\\OneDrive\\Documentos\\GitHub\\EDA2001\\Trabalho\\"

# (2) Gráfico do caso médio da árvore Rubro-Negra:

with open(generalPath + "RedBlackTree\\PerformanceAverageCase.txt", 'r') as f:
    lines = f.readlines()

averageVector = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        averageVector[j] += float(vector[j])/10

xpoints = np.array([x for x in range(0, len(averageVector))])
ypoints = np.array(averageVector)

plt.plot(xpoints, ypoints, label="Average")
f.close()

# (3) Gráfico do pior caso da árvore Rubro-Negra:

with open(generalPath + "RedBlackTree\\PerformanceWorstCase.txt", 'r') as f:
    lines = f.readlines()

worstVector = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        worstVector[j] = float(vector[j])

xpoints = np.array([x for x in range(0, len(averageVector))])
ypoints = np.array(worstVector)

plt.plot(xpoints, ypoints, label="Worst")

plt.title("Average Case vs Worst Case")
plt.xlabel("Elementos na árvore")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\RedBlackTree.png")

f.close()