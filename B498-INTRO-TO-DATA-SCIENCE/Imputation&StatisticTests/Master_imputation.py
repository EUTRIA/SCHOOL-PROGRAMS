import pandas as pd
import numpy as np
import scipy
import matplotlib
import matplotlib.pyplot as plt
from sklearn.impute import SimpleImpute
import statistics as stat

# Imputing the missing data of the height column using the mean method
Master_df = pd.read_csv('Master.csv')

print("Before Imputation: ")
print(Master_df['height'].head(25)) # before imputation
print("Mean: ")
print(stat.mean(Master_df['height'])) # returns nan because of a column has nan values

fill_NaN = SimpleImputer(missing_values=np.nan, strategy='mean')
imputed_height_data =fill_NaN.fit_transform(Master_df[['height']])

imputed_Master_height = pd.DataFrame(imputed_height_data, columns = ['height'])

Master_df = imputed_Master_height

print("After Imputation: ")
print(Master_df['height'].head(25))  
print("Mean: ")
print(stat.mean(Master_df['height']))


# Interpolating weight column uisng linear interpolation
PolyInterp_Master_weight_df = pd.read_csv('Master.csv')

print("Before Polynomial Interpolation: ")
print(PolyInterp_Master_weight_df['weight'].head(25)) # before Polynomial Interpolation

PolyInterp_Master_weight_df['weight'] = PolyInterp_Master_weight_df['weight'].interpolate(method ='polynomial', order=2)

print("After Polynomial Interpolation: ")
print(PolyInterp_Master_weight_df['weight'].head(25))  # after Polynomial Interpolation
