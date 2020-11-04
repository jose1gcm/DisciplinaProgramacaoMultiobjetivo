# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import math



def rastr(xx):
#   d = length(xx)
   d=np.array(range(len(xx)))
   sum=0
   for xxx in xx:
       sum+=math.pow(xxx,2)-10*math.cos(2*math.pi*xxx)
   #sum = sum(xx^2 - 10*math.cos(2*math.pi*xx))
   y=10*d+sum
   return(y)

def rosen(xx):
  d = np.array(range(len(xx)))
  sum = 0
  # ver se vai ter que colocar um for aqui
  xi = xx[1:(d-1)]
  xnext = xx[2:d]
  sum += (100*math.pow((xnext-math.pow(xi,2)),2) + math.pow((xi-1),2))
	
  y = sum
  return(y)
  
  
def rosensc(xx):
    xxbar = 15*xx - 5
    xibar = xxbar[1:3]
    xnextbar = xxbar[2:4]
    sum = 0
    sum += (100*math.pow((xnextbar-math.pow(xibar,2)),2) + math.pow((1 - xibar),2))
  
    y = (sum - 3.827*math.pow(10,5)) / (3.755*math.pow(10,5))
    return y
    
#------------------------------------------------------------------------------
    


xx = [2,5,4,3,1,13,15,9,6]

print("DADOS")
print(xx)
plt.plot(xx,'r^:',color='blue')
plt.show()

print("RASTR")
resultado=rastr(xx)
print(resultado)
plt.plot(resultado,'r^:',color='green')
plt.show()

print("ROSEN")
#resultado_Rosen=rosen(xx)
#print(resultado_Rosen)
#plt.plot(resultado_Rosen,'r^:',color='green')
#plt.show()

print("ROSENSC")
#resultado_Rosensc=rosensc(xx)
#print(resultado_Rosen)
#plt.plot(resultado_Rosen,'r^:',color='green')
#plt.show()
#x1=[0,2,4,13,2,1]
#x2=[0,6,7,2,3,1]
#z0=(0,0)
#plt.plot(x1,x2,'r^:',color='blue')
#plt.show()

#$$f(x) = (x + 2)^2 - 16exp(-(x - 2)^2)$$

#conjunto de dados
trX = np.linspace(-2, 2, 101)

trY = 3 + 2 * trX + np.random.randn(*trX.shape) * 0.33
plt.plot(trY,'r^:',color='blue')
plt.show()
#parâmetros
num_steps = 100
learningRate = 0.10
criteria = 1e-8
b_0 = 1
b_1 = 1

for step in range(0, num_steps):
    b_0_gradient = 0
    b_1_gradient = 0
    N = float(len(trX))
    for i in range(0, len(trX)):
        b_0_gradient -= (2/N) * (trY[i] - (b_0 + b_1 * trX[i]))
        b_1_gradient -= (2/N) * (trY[i] - (b_0 + b_1 * trX[i])) * trX[i]
        
    b_0 = b_0 - (learningRate * b_0_gradient)
    b_1 = b_1 - (learningRate * b_1_gradient)
    if max(abs(learningRate * b_0_gradient), abs(learningRate * b_1_gradient)) < criteria:
        break
    

print("Valores obtidos:", b_0, b_1, "número de passos:", step)

