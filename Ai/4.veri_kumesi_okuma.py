import os
# !pip install pandas
import pandas as pd
import torch

os.makedirs(os.path.join('..', 'data'), exist_ok=True)
veri_dosyasi = os.path.join('..', 'data', 'house_tiny.csv')
with open(veri_dosyasi, 'w') as f:
    f.write('NumRooms,Alley,Price\n')  # Sütun adları
    f.write('NA,Pave,127500\n')  # Her satır bir örnek temsil eder
    f.write('2,NA,106000\n')
    f.write('4,NA,178100\n')
    f.write('NA,NA,140000\n')

veri = pd.read_csv(veri_dosyasi)
print(veri)

girdiler, ciktilar = veri.iloc[:, 0:2], veri.iloc[:, 2]
girdiler = girdiler.fillna(girdiler.mean())
print(girdiler)

girdiler = pd.get_dummies(girdiler, dummy_na=True)
print(girdiler)

X, y = torch.tensor(girdiler.values), torch.tensor(ciktilar.values)
print(X, "\n",y)
