from random import randint

# Este script genera casos random con costo random y con una cantidad fija de trabajos,
# pero variando la amplitud entre el costo mínimo y el máximo de los trabajos
# Ej: En una instancia el costo de un trabajo toma valores entre 1 y 100, y
# en otra entre 1 y 20

trabajos_a_organizar = 100
repeticiones = 10
costo_min = 1
costo_max = 100
costo_max_step = 10

for costo_m in range(0, costo_max // costo_max_step):
    for r in range(0, repeticiones):
        print('{}'.format(trabajos_a_organizar))

        for trabajos in range(1, trabajos_a_organizar + 1):
            trabajo_costos = []
            for costo_preparacion in range(1, trabajos + 1):
                trabajo_costos.append(randint(costo_min, costo_max - costo_m * costo_max_step))

            print("{}".format(" ".join(str(i) for i in trabajo_costos)))

print("0")