import pandas as pd
import numpy as np

# Creating DataFrame of data
pd.options.display.float_format = '{:,.2f}'.format


pd.options.display.max_rows = 200
                                    # Expanding display limits
pd.options.display.max_columns = 100


crypto_df = pd.read_csv('crypto_sample.csv', header = None)# Reading csv to DataFrame
                                    
crypto_df.set_axis(['Code','Date', 'Open', 'High', 'Low', 'Close', 'Volume', 'VWAP', 'TWAP'], axis = 1, inplace = True)

print(crypto_df.head())

# filtering dataframe to only keep records of GWA codes
gwp_code = crypto_df['Code'].str[:3]
crypto_df = crypto_df[gwp_code == 'GWA']
print(crypto_df.head())

# Pivoting dataframe and setting the result into a new dataframe 
# in the new dataframe GWA codes will replace the columns and each row will represent the price of each one of the codes 
# at a specific data

pivoted_crypto_df= crypto_df.pivot(index = 'Date', columns ='Code', values = 'VWAP').reset_index().rename_axis(None, axis = 1)


pivoted_crypto_df['Date'] = pd.to_datetime(pivoted_crypto_df['Date'])
pivoted_crypto_df = pivoted_crypto_df.sort_values(by = 'Date') # Sorting the dates column 


pivoted_crypto_df = pivoted_crypto_df.reset_index().drop('index', axis = 1).fillna(0) # Dropping unsorted index column and filling null values with 0
print(pivoted_crypto_df.head())
