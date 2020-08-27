A = list(map(float,input().split()))
B = list(map(float,input().split()))

Ab = (A[1]*A[2])+(B[1]*B[2])
print('VALOR A PAGAR: R$ {:0.2f}'.format(Ab))