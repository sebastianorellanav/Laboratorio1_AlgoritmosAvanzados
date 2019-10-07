//Algoritmo 8 reinas
algoritmo(n)
X = matriz[n][n]
X[1] = 0
k = 1
mientras k > 0
	repetir
		X[k] = X[k] + 1
	(hasta X[k] > n) o (colocar(X[k],k,X))
	si (X[k] <= n) entonces
		si (k = n) entonces escribir(X)
		si no k = k+1
			X(k) = 0
	si no k = k-1

	funcion colocar = determina si se puede o no colcoar la reinas
	