adj = []
circuit = []


def getEulerCircuit(here):

    for there, val in enumerate(adj):
        while adj[here][there] > 0:
            adj[here][there] -= 1
            adj[there][here] -= 1
            getEulerCircuit(there)
    circuit.append(here)


for _ in range(7):
    adj.append([0] * 7)

adj[0][1] = 1
adj[1][2] = 1
adj[2][4] = 1
adj[4][5] = 1
# adj[5][6] = 1
# adj[6][2] = 1
adj[2][3] = 1
# adj[3][0] = 1

getEulerCircuit(0)
print(adj)
