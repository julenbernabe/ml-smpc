import pandas as pd

# IMPORTANT: CHANGE THIS VARIABLE DEPENDING ON THE NUMBER OF PLAYERS WANTED

n = 3

equivalences = {
    "Iris-setosa": 0,
    "Iris-versicolor": 1,
    "Iris-virginica": 2
    }

def mpspdz(n_players: int, df: pd.DataFrame):
    txts = [('mp-spdz/input' + str(i) + '.txt') for i in range (n_players)]
    for k in range (len(txts)):
        with open(txts[k], 'w+') as f:
            f.write(df.iloc[[(k * (len(df.index) // n_players) + i) for i in range (len(df.index) // n_players)]].to_csv(sep = " ", header = False, index = False))

def scalemamba(n_players: int, df: pd.DataFrame):
    df[['SepalLengthCm', 'SepalWidthCm', 'PetalLengthCm', 'PetalWidthCm']] = df[['SepalLengthCm', 'SepalWidthCm', 'PetalLengthCm', 'PetalWidthCm']].multiply(10).astype('int')
    txts = [('scale-mamba/input' + str(i) + '.txt') for i in range (n_players)]
    for k in range (len(txts)):
        with open(txts[k], 'w+') as f:
            f.write(df.iloc[[(k * (len(df.index) // n_players) + i) for i in range (len(df.index) // n_players)]].to_csv(sep = "\n", header = False, index = False))

def main(n_players: int):
    # Import Iris.csv
    df = pd.read_csv('Iris.csv')
    # Shuffle rows in the CSV
    df = df.sample(frac = 1).reset_index()
    # Drop 'Id column (does not give information)
    df = df.drop( labels = ['Id', 'index'], axis = 1)
    # Change 'Species' variable to numeric values using equivalences (variable above)
    df = df.replace(equivalences)
    mpspdz(n_players, df)
    scalemamba(n_players, df)


main(n)