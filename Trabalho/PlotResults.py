# (1) Caminho da pasta do trabalho:
generalPath = "C:\\Users\\bruni\\OneDrive\\Documentos\\GitHub\\EDA2001\\Trabalho\\"

with open(generalPath + "RedBlackTree\\PerformanceAverageCase.txt", 'r') as f:
    lines = f.readlines()

averageVector = []
for i in range(100): averageVector.append(0)

for line in lines:
    vector = line.split()
    j = 0
    for number in vector:
        averageVector[j] += int(number)/10
        j += 1

print(averageVector)