import matplotlib.pyplot as plt
import numpy as np

datos = np.loadtxt("tray.txt")

#Aqui se hacen los plots
plt.figure()
plt.title("x Vs t")
plt.xlabel("t")
plt.ylabel("x")
plt.plot(datos[:,2], datos[:,0])
plt.savefig("pos.png")
plt.close()

plt.figure()
plt.title("v Vs t")
plt.xlabel("t")
plt.ylabel("v")
plt.plot(datos[:,2], datos[:,1])
plt.savefig("vel.png")
plt.close()

plt.figure()
plt.title("v Vs x")
plt.xlabel("x")
plt.ylabel("v")
plt.plot(datos[:,0], datos[:,1])
plt.savefig("phase.png")
plt.close()
