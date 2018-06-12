import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('temp.log', header=None, parse_dates=True, index_col=0,
    names=['time', 'temperature'])

df.plot()
plt.show()
