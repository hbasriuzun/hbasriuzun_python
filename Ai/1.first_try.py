import torch

x = torch.arange(12, dtype=torch.float32)
x
x.shape
x.numel()
print(x.shape)
print(x.numel())
print(x)


X = x.reshape(3, 4)
X

print(X)

torch.zeros((2, 3, 4))
print(torch.zeros((2, 3, 4)))

print("\n")

torch.ones((2, 3, 4))
print(torch.ones((2, 3, 4)))

x = torch.tensor([1.0, 2, 4, 8])
y = torch.tensor([2, 2, 2, 2])
print(x + y, x - y, x * y, x / y, x ** y)  

X = torch.arange(12, dtype=torch.float32).reshape((3,4))
Y = torch.tensor([[2.0, 1, 4, 3], [1, 2, 3, 4], [4, 3, 2, 1]])
torch.cat((X, Y), dim=0), torch.cat((X, Y), dim=1)
print(torch.cat((X, Y), dim=0),"\n", torch.cat((X, Y), dim=1))