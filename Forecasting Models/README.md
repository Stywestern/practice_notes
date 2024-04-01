# Introduction
This project was created to train forecasting models with Karaca Retail sales data, compare commonly used models in this specific task, and provide demos of Artificial Intelligence models to my colleagues. I aimed to create a modular structure so that notebooks containing different data and targeting other objectives could be easily modified. My goal was to provide an infrastructure for such AI developments in the future.

## Project Content
### Folders and Files
* DATASETS: Holds raw and processed data
* MODELS: Stores trained and selected final models for deployment
* RNN Model Graphs: Contains images showing the internal architecture of Recurrent Neural Network models
* saved_GRU and saved_LSTM: Stores parameters for RNN models trained per epoch
* catboost_info: Stores information related to the training of the Categorical Boosting algorithm
* column_docs: Holds information regarding the columns of raw data
* normalization_stats: Stores normalization statistics

### Notebooks
Notebooks can be classified into 4 groups:
1) Data Analysis Notebooks: Notebooks used to examine and manipulate data
   * EDA 1 (General).ipynb: General overview of the data
   * EDA 2 (Descriptive Statistics).ipynb: Detailed information about columns
   * EDA 3 (Further Cleaning).ipynb: Cleaning the data according to targets and requests
2) Model Notebooks: Notebooks where models are trained, evaluated, and explained
   * RNN Models - Main.ipynb: Main notebook about RNN models
   * RNN Models - Prototype.ipynb: Prototype of main RNN models without multiple sequence sizes
   * Linear Models.ipynb: Linear regression models
   * Tree Models.ipynb: Tree models
   * ARIMA Models.ipynb: ARIMA models
   * Prophet Models.ipynb: Open-source forecasting algorithm developed by Meta
3) Application Notebooks: Notebooks created using the Gradio library to create a user interface
   * Gradio - RNN.ipynb: Gradio for RNN models
   * Gradio - Linear.ipynb: Gradio for the best linear model
   * Gradio - Tree.ipynb: Gradio for the best tree model
   * Gradio - Prophet.ipynb: Gradio for the best Prophet model
4) Functional Notebook: A notebook containing several functions
   * Utilities.ipynb
  
## Recommended Viewing Order by the Author
Most notebooks can function independently, but they contain many common functions and sections with each other. To avoid constantly repeating the same explanations for the reader, I preferred not to include general explanations for notebooks in the same group. Therefore, I placed the general explanations for notebooks in the same group as the first element of each group. Other notebooks contain explanations of parts not present in others in the same group. If you read them as listed in the "Notebooks" section, you can see all the explanations.

## Notes
### About Model Performances:
The dataset was not comprehensive enough to produce a useful model generalized to the task, but if a performance ranking is still needed, it can be shown as Tree > Prophet > Linear > RNN. I did not optimize NN models, so their relatively low performance can be explained this way. If there is to be any future development, I recommend giving more weight to NN models compared to others.```
