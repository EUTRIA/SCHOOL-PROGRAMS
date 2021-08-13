import tensorflow as tf
from tensorflow import keras

# define our model and create our input layer
# feed forward NN with Sequential 

model = keras.Sequential() 
input_layer = keras.layers.Dense(4, input_shape=[4], activation='sigmoid')
model.add(input_layer)

# Add one hidden layer 
hidden_layer = keras.layers.Dense(8, activation='relu')
model.add(hidden_layer)

#output layer
#use the sigmoid function because our output is expected to be 0 or 1.
output_layer = keras.layers.Dense(1, activation='sigmoid')
model.add(output_layer)

# Set the optimizer
# The learning rate determines the step size at each iteration, watch the video below.
# The momemntum parameter determines the acceleration of SGD in relevant direction of the gradient. 
#gd = tf.keras.optimizers.SGD(learning_rate=0.09, momentum=0.85)
gd = tf.keras.optimizers.SGD(learning_rate=0.075, momentum=0.95)
model.compile(optimizer=gd,loss='mean_squared_error', metrics = ['accuracy'])

#prepare data
x = X_train
y = y_train

#epoch is the number of iterations over the entire input data
# steps_per_epoch is the number of iterations per batch before the epoch is finished
model.fit(x, y, epochs=7000, steps_per_epoch=16)
#model.summary()

# testing our data 
results = model.predict(tf.constant(X_test), verbose = 0 , steps = 1)
# outputing results
result_data = list(zip(results,y_test))
results_df = pd.DataFrame(result_data, columns= ['Predicted Output', 'Actual Output'])

def accuracy(test_data, predicted_data):
    correct = 0
    for i in range(len(test_data)):
        if test_data[i] == predicted_data[i]:
            correct += 1 
    return correct / float(len(predicted_data)) * 100

print(f'Accuracy: {np.round(accuracy(y_test,np.round(results)))}%')
