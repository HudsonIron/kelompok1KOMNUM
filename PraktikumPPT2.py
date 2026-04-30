import numpy as np
import matplotlib.pyplot as plt

def fungsi(val):
    return val**3 - val - 2

def metode_rf(kiri, kanan, toleransi=1e-4, maks_iter=100):
    f_kiri = fungsi(kiri)
    f_kanan = fungsi(kanan)

    if f_kiri * f_kanan >= 0:
        print("Interval tidak valid")
        return None

    for langkah in range(maks_iter):
        titik = (kiri * f_kanan - kanan * f_kiri) / (f_kanan - f_kiri)
        f_titik = fungsi(titik)

        print(f"Iter {langkah}: x = {titik:.6f}, f(x) = {f_titik:.6f}")

        if abs(f_titik) < toleransi:
            return titik

        if f_kiri * f_titik < 0:
            kanan = titik
            f_kanan = f_titik
        else:
            kiri = titik
            f_kiri = f_titik

    return titik

hasil_akar = metode_rf(1, 2)

data_x = np.linspace(0, 3, 100)
data_y = fungsi(data_x)

plt.axhline(0)
plt.plot(data_x, data_y, label="fungsi(x)")
plt.scatter(hasil_akar, fungsi(hasil_akar))
plt.title("Grafik Fungsi dan Akar (Regula Falsi)")
plt.legend()
plt.grid()

plt.show()
