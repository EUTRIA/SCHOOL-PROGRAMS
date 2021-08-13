#3 Write your code here
import plotly.express as px
import scipy as sp
from scipy import stats

#interpolation
baseball_stat_df = pd.read_csv('baseball_stats.csv')
print('Before interpolation: ')
print(baseball_stat_df.head(25))

print('\nAfter Interpolation: ')
baseball_stat_df = baseball_stat_df.interpolate(method ='polynomial', order = 2)
print(baseball_stat_df.head(25))

print('/nHistogram for handedness')
baseball_handness_fig = px.histogram(baseball_stat_df['handedness'], 
                                     nbins=20,
                                    x = 'handedness',
                                    title ='Histogram of handedness') 
baseball_handness_fig.show()

# Shapiro-Wilk test
   
handedness = baseball_stat_df['handedness'] # encoding the handedness column & removing names column
handedness  = handedness.astype('category')
handedness  = handedness.cat.codes
baseball_stat_df['handedness'] = handedness # B = 0, L =1, R =2, no input = -1

    
encoded_baseball_stat_df = baseball_stat_df.drop(columns = 'name')# Data has empty strings '' ; replacing them with 0
encoded_baseball_stat_df['height'] = pd.to_numeric(encoded_baseball_stat_df['height'],errors='coerce')
encoded_baseball_stat_df['weight'] = pd.to_numeric(encoded_baseball_stat_df['weight'],errors='coerce')
encoded_baseball_stat_df = encoded_baseball_stat_df.fillna(0)

print('\nFinal product: ')
print(encoded_baseball_stat_df.head(25))


W,P = sp.stats.shapiro(encoded_baseball_stat_df)
if P<0.05 :  # test statistics at 95% confidence 
    print('Reject: data is not normal')
else:
    print('Accept: data is normal') # we should get this as our output, we are 95% confident data is normally distributed
#print(encoded_baseball_stat_df.head(25))
#encoded_baseball_stat_df.isnull().sum()
#print(encoded_baseball_stat_df.dtype)


# T-Test 
left_handed_hitters_df = encoded_baseball_stat_df[encoded_baseball_stat_df['handedness'] == 1]
right_handed_hitters_df = encoded_baseball_stat_df[encoded_baseball_stat_df['handedness'] == 2]
left_handed_hitters_df.drop(columns = 'handedness', inplace = True)
right_handed_hitters_df.drop(columns = 'handedness', inplace = True)

print('Left handed hitters: ')
print(left_handed_hitters_df.head(25))
print('\nRight handed hitters: ')
print(right_handed_hitters_df.head(25))

results = scipy.stats.ttest_ind(left_handed_hitters_df, right_handed_hitters_df, equal_var=False)
print("Two Sample Test Statistics")
print(results)

if results[0][0]<0.05 : # test statistics at 95% confidence 
        print('Reject: Null hypothesis')  
else:
        print('Accept: Null Hypothesis') 
