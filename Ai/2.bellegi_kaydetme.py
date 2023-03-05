import torch

X = torch.tensor([1.0, 2, 4, 8])
Y = torch.tensor([2, 2, 2, 2])

Z = torch.zeros_like(Y)
print('id(Z):', id(Z))
Z[:] = X + Y
print('id(Z):', id(Z))