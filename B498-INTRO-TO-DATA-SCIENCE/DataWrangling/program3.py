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

# filtering dataframe to only keeping records of GWA codes
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

# Shifiting dataframe to be able to caculate the [7,14,21,28] days prior
#New dataframe without date column to avoid errors when calculating returns
return_df = pivoted_crypto_df.drop( columns = 'Date')


for i, x in enumerate (range(len(pivoted_crypto_df.index))):#Calculating 
    delta_7 = return_df / return_df.shift(7) - 1.0
    delta_14 = return_df / return_df.shift(14) - 1.0
    delta_21 = return_df / return_df.shift(21) - 1.0
    delta_28 = return_df / return_df.shift(28) - 1.0
    

delta_7 = delta_7.set_index(pivoted_crypto_df['Date']).reset_index()#putting the date back into the dataframe as a column
delta_14 = delta_14.set_index(pivoted_crypto_df['Date']).reset_index()
delta_21 = delta_21.set_index(pivoted_crypto_df['Date']).reset_index()
delta_28 = delta_28.set_index(pivoted_crypto_df['Date']).reset_index()


returns_dict = {# dictionary containing all results
    7: delta_7,
    14: delta_14,
    21: delta_21,
    28: delta_28 
}

returns_dict[7].head(15)

# Melting the shifted dataframe to create an analytical base table (ABT) where each row contains all of the relevant information for a particular coin on a particular date.
#melting all 4 dataframes
melted_7 = delta_7.melt(id_vars=['Date'], value_name ='delta_7', var_name = 'Code')
melted_14 = delta_14.melt(id_vars=['Date'], value_name ='delta_14', var_name = 'Code')
melted_21 = delta_21.melt(id_vars=['Date'], value_name ='delta_21', var_name = 'Code')
melted_28 = delta_28.melt(id_vars=['Date'], value_name ='delta_28', var_name = 'Code')


melted_dfs = [melted_7, melted_14, melted_21, melted_28]# storing all 4 dataframes in melted_dfs


strat_evaluation_df = melted_7.copy(deep =True) # merging all the data into one dataframe strat_evauluation_df
strat_evaluation_df =strat_evaluation_df.assign(delta_14 = melted_14['delta_14'])
strat_evaluation_df = strat_evaluation_df.assign(delta_21 = melted_21['delta_21'])
strat_evaluation_df = strat_evaluation_df.assign(delta_28 = melted_28['delta_28'])

strat_evaluation_df.tail()
