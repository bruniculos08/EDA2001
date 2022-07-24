import matplotlib.pyplot as plt
import numpy as np

# (1) Caminho da pasta do trabalho:
generalPath = "C:\\Users\\bruni\\OneDrive\\Documentos\\GitHub\\EDA2001\\Trabalho\\"

# (2) Gráfico do caso médio da árvore Rubro-Negra:

with open(generalPath + "RedBlackTree\\PerformanceAverageCase.txt", 'r') as f:
    lines = f.readlines()

averageVectorRB = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        averageVectorRB[j] += float(vector[j])/10

xpointsAverageRB = np.array([x for x in range(0, len(averageVectorRB))])
ypointsAverageRB = np.array(averageVectorRB)

plt.plot(xpointsAverageRB, ypointsAverageRB, label="Average (Red-Black)")
f.close()

# (3) Gráfico do pior caso da árvore Rubro-Negra:

with open(generalPath + "RedBlackTree\\PerformanceWorstCase.txt", 'r') as f:
    lines = f.readlines()

worstVectorRB = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        worstVectorRB[j] = float(vector[j])

xpointsWorstRB = np.array([x for x in range(0, len(worstVectorRB))])
ypointsWorstRB = np.array(worstVectorRB)

plt.plot(xpointsWorstRB, ypointsWorstRB, label="Worst (Red-Black)")

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

averageVectorAVL = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        averageVectorAVL[j] += float(vector[j])/10

xpointsAverageAVL = np.array([x for x in range(0, len(averageVectorAVL))])
ypointsAverageAVL = np.array(averageVectorAVL)

plt.plot(xpointsAverageAVL, ypointsAverageAVL, label="Average (AVL)")
f.close()

# (5) Gráfico do pior caso da árvore AVL:

with open(generalPath + "AVLTree\\PerformanceWorstCase.txt", 'r') as f:
    lines = f.readlines()

worstVectorAVL = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        worstVectorAVL[j] = float(vector[j])

xpointsWorstAVL = np.array([x for x in range(0, len(worstVectorAVL))])
ypointsWorstAVL = np.array(worstVectorAVL)

plt.plot(xpointsWorstAVL, ypointsWorstAVL, label="Worst (AVL)")

plt.title("Average Case vs Worst Case")
plt.xlabel("Elementos na árvore")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\AVLTree.png")
plt.close()
f.close()

# (8) Plotando todos os gráficos em um só:

plt.plot(xpointsAverageRB, ypointsAverageRB, label="Average (RB)")
plt.plot(xpointsAverageAVL, ypointsAverageAVL, label="Average (AVL)")
plt.title("Average Cases")
plt.xlabel("Elementos na árvore")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\AllTreesAverage.png")
plt.close()

plt.plot(xpointsWorstRB, ypointsWorstRB, label="Worst (RB)")
plt.plot(xpointsWorstAVL, ypointsWorstAVL, label="Worst (AVL)")

plt.title("Worst Cases")
plt.xlabel("Elementos na árvore")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\AllTreesWorst.png")
plt.close()