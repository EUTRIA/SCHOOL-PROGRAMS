# Implementing a ANN to predict if a passanger survived or perished 
import numpy as np
import pandas as pd  
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

titanic_data = pd.read_csv("titanic_data.csv") # Setting up DataFrame
titanic_df = pd.DataFrame(data = titanic_data, columns = ['Pclass', 'Sex','Age','Fare','Survived'])


titanic_df.interpolate(method = 'linear' , inplace = True)# Filling missing values and rounding 
titanic_df = titanic_df.round(0)


sex = titanic_df['Sex']# encoding Sex column 
sex = sex.astype('category')
sex = sex.cat.codes
titanic_df['Sex'] = sex


titanic_df[['Sex', 'Pclass']] = np.float64(titanic_df[['Sex', 'Pclass']])# changing Sex & Pclass types to float64 

titanic_df.head()
#titanic_df.isnull().sum()
#titanic_df.dtypes


# Normalizing data
data = titanic_df[['Pclass', 'Age', 'Fare']]
scaler = StandardScaler(with_mean = 0, with_std = 1)

scaled = scaler.fit_transform(data)# transfroming data 

titanic_df[['Pclass', 'Age', 'Fare']] = scaled# replacing orginal with normalized data
titanic_df.head()
#print(scaled)


#Splitting data 70% training 30% test
X = titanic_df[['Pclass', 'Sex', 'Age', 'Fare']] # input data
y = titanic_df[['Survived']] # output


X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0, test_size=0.3)


y_test = np.concatenate(y_test.values) # adjusting y_test shape to be equal to X_test shape
#print(X_train.shape)
#print(X_test.shape)
#print(y_train.shape)
#print(y_test.shape)


# Creating and evaluating Neural Network 
def accuracy(test_data, predicted_data):
    correct = 0
    for i in range(len(test_data)):
        if test_data[i] == predicted_data[i]:
            correct += 1 
    return correct / float(len(predicted_data)) * 100

class Neural_Network(object):
  def __init__(self):
  #parameters
    self.inputSize = 4
    self.outputSize = 1
    self.hiddenSize = 2

    self.W1 = np.random.randn(self.inputSize, self.hiddenSize) # (4x2) weight matrix from input to hidden layer
    self.W2 = np.random.randn(self.hiddenSize, self.outputSize) # (4x1) weight matrix from hidden to output layer

  def forward(self, X):  #forward propagation through our network
  
    self.z = np.dot(X, self.W1) # dot product
    self.z2 = self.sigmoid(self.z) # activation function
    self.z3 = np.dot(self.z2, self.W2) # dot product of hidden layers
    o = self.sigmoid(self.z3) # final activation function
    return o

  def sigmoid(self, s):
    return 1/(1+np.exp(-s))# activation function

  def sigmoidPrime(self, s):
    return s * (1 - s) #derivative of sigmoid

  def backward(self, X, y, o):# backward propagate through the network
    self.o_error = y - o # error in output
    self.o_delta = self.o_error*self.sigmoidPrime(o) # applying derivative of sigmoid to error

    self.z2_error = self.o_delta.dot(self.W2.T) # how much our hidden layer weights contributed to output error
    self.z2_delta = self.z2_error*self.sigmoidPrime(self.z2) # applying derivative of sigmoid to z2 error

    self.W1 += X.T.dot(self.z2_delta) # adjusting first set (input --> hidden) weights
    self.W2 += self.z2.T.dot(self.o_delta) # adjusting second set (hidden --> output) weights

  def train(self, X, y):
    o = self.forward(X)
    self.backward(X, y, o)

  def saveWeights(self):
    np.savetxt("w1.txt", self.W1, fmt="%s")
    np.savetxt("w2.txt", self.W2, fmt="%s")

  def predict(self):
    print ("Predicted data based on trained weights: ");
    print ("Input (scaled): \n" + str(X_test));
    print ("Output: \n" + str(self.forward(X_test)));
    print ("Actual Output: \n" + str(y_test))

NN = Neural_Network()
for i in range(1000): # trains the NN 1,000 times
  print ("# " + str(i))
  #print ("Input (scaled): \n" + str(X_train))
  #print ("Actual Output: \n" + str(y_train))
  #print ("Predicted Output: \n" + str(NN.forward(X_train)))
  print ("Loss: \n" + str(np.mean(np.square(y_train - NN.forward(X_train))))) # mean sum squared loss
  NN.train(X_train, y_train)

NN.saveWeights()
NN.predict()
print(f'Accuracy: {np.round(accuracy(y_test,np.round(NN.forward(X_train))))}%')
