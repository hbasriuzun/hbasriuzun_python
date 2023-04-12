import torch
import numpy as np

X = torch.tensor([1.0, 2, 4, 8])
Y = torch.tensor([2, 2, 2, 2])

A = X.numpy()
B = torch.from_numpy(A)
print(type(A), type(B))
