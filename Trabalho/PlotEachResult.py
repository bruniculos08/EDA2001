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

plt.plot(xpoints, ypoints, label="Average (Red-Black)")
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

plt.plot(xpoints, ypoints, label="Worst (Red-Black)")

plt.title("Average Case vs Worst Case")
plt.xlabel("Elementos na árvore")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\RedBlackTree.png")
plt.close()
f.close()

# (4) Gráfico do caso médio da árvore AVL:

with open(generalPath + "AVLTree\\PerformanceAverageCase.txt", 'r') as f:
    lines = f.readlines()

averageVector = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        averageVector[j] += float(vector[j])/10

xpoints = np.array([x for x in range(0, len(averageVector))])
ypoints = np.array(averageVector)

plt.plot(xpoints, ypoints, label="Average (AVL)")
f.close()

# (5) Gráfico do pior caso da árvore AVL:

with open(generalPath + "AVLTree\\PerformanceWorstCase.txt", 'r') as f:
    lines = f.readlines()

worstVector = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        worstVector[j] = float(vector[j])

xpoints = np.array([x for x in range(0, len(averageVector))])
ypoints = np.array(worstVector)

plt.plot(xpoints, ypoints, label="Worst (AVL)")

plt.title("Average Case vs Worst Case")
plt.xlabel("Elementos na árvore")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\AVLTree.png")
plt.close()
f.close()
