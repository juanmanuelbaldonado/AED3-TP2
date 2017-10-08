from random import randint

trabajos_a_organizar_min = 10
trabajos_a_organizar_max = 200
trabajos_step = 5
repeticiones = 10
costo_min = 1
costo_max = 100

for n in range(trabajos_a_organizar_min, trabajos_a_organizar_max + 1, 10):
    for r in range(0, repeticiones):
        print('{}'.format(n))

        for trabajos in range(1, n + 1):
            trabajo_costos = []
            for costo_preparacion in range(1, trabajos + 1):
                trabajo_costos.append(randint(costo_min, costo_max))

            print("{}".format(" ".join(str(i) for i in trabajo_costos)))

print("0")