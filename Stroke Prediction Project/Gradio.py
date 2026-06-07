import gradio as gr

########################## Model ########################################

import torch
import torch.nn as nn

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

class Net2(nn.Module):
    def __init__(self, input_size, hidden_size, num_classes):
        super(Net2, self).__init__()
        self.input_size = input_size
        self.l1 = nn.Linear(input_size, hidden_size)
        self.l2 = nn.Linear(hidden_size, hidden_size//2) 
        self.l3 = nn.Linear(hidden_size//2, num_classes)
        
        self.relu = nn.ReLU()
        self.lrelu = nn.LeakyReLU(negative_slope=0.01)
        self.elu = nn.ELU()
        self.tanh = nn.Tanh()
        
        self.sigmoid = nn.Sigmoid()
        
        self.dropout = nn.Dropout(0.2) 
    
    def forward(self, x):
        out = self.l1(x)
        out = self.dropout(out)
        out = self.lrelu(out)
        out = self.l2(out)
        out = self.dropout(out)
        out = self.lrelu(out)
        out = self.l3(out)
        out = self.dropout(out)
        out = self.sigmoid(out)
        
        return out

input_size = 17
hidden_size = 16
num_classes = 1

# Dropdowns
gender_choices = [1, 0]
gender_dropdown = gr.inputs.Dropdown(choices=gender_choices, label="Male: 0, Female: 1")

hypertension_choices = [1, 0]
hypertension_dropdown = gr.inputs.Dropdown(choices=hypertension_choices, label="Normal: 0, Has Hypertension: 1")

heart_disease_choices = [1, 0]
heart_disease_dropdown = gr.inputs.Dropdown(choices=heart_disease_choices, label="Normal: 0, Has Heart Disease: 1")

ever_married_choices = [1, 0]
ever_married_dropdown = gr.inputs.Dropdown(choices=ever_married_choices, label="Never Married Before: 0, Married At Least Once: 1")

residence_type_choices = [1, 0]
residence_type_dropdown = gr.inputs.Dropdown(choices=residence_type_choices, label="Urban: 0, Rural: 1")

work_type_choices = ['Private', 'Self Employed', 'Goverment Job', 'Never Worked', 'Children']
work_type_dropdown = gr.inputs.Dropdown(choices=work_type_choices, label="Choose a work type")

smoking_choices = ['Never Smoked', 'Formerly Smoked', 'Smokes Regularly', 'Not Specified']
smoking_dropdown = gr.inputs.Dropdown(choices=smoking_choices, label="Choose Smoking Status")

def predict_probability(gender, age, hypertension, heart_disease, ever_married,
    residence_type, glucose, bmi, work_type, smoking):
    
    # Standardize
    age_mean, age_std = 41.87051043401588, 21.756481840504232
    age = (age - age_mean) / age_std
    
    glucose_mean, glucose_std = 93.32225629469971, 32.476350671309035
    glucose = (glucose - glucose_mean) / glucose_std
    
    bmi_mean, bmi_std = 28.30227972097165, 7.021764583221495
    bmi = (bmi - bmi_mean) / bmi_std

    features = []
        
    # Set the features
    if work_type == "Goverment Job":
        if smoking == "Not Specified":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 1, 0, 0, 0, 0, 1, 0, 0, 0]      
        if smoking == "Formerly Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 1, 0, 0, 0, 0, 0, 1, 0, 0]                                                                                                       
        if smoking == "Never Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 1, 0, 0, 0, 0, 0, 0, 1, 0]                                                                                                      
        if smoking == "Smokes Regularly":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 1, 0, 0, 0, 0, 0, 0, 0, 1]
            
    if work_type == "Never Worked":
        if smoking == "Not Specified":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 1, 0, 0, 0, 1, 0, 0, 0]      
        if smoking == "Formerly Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 1, 0, 0, 0, 0, 1, 0, 0]                                                                                                       
        if smoking == "Never Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 1, 0, 0, 0, 0, 0, 1, 0]                                                                                                      
        if smoking == "Smokes Regularly":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 1, 0, 0, 0, 0, 0, 0, 1]
            
    if work_type == "Private":
        if smoking == "Not Specified":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 1, 0, 0, 1, 0, 0, 0]      
        if smoking == "Formerly Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 1, 0, 0, 0, 1, 0, 0]                                                                                                       
        if smoking == "Never Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 1, 0, 0, 0, 0, 1, 0]                                                                                                      
        if smoking == "Smokes Regularly":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 1, 0, 0, 0, 0, 0, 1]
            
    if work_type == "Self Employed":
        if smoking == "Not Specified":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 1, 0, 1, 0, 0, 0]      
        if smoking == "Formerly Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 1, 0, 0, 1, 0, 0]                                                                                                       
        if smoking == "Never Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 1, 0, 0, 0, 1, 0]                                                                                                      
        if smoking == "Smokes Regularly":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 1, 0, 0, 0, 0, 1]
            
    if work_type == "Children":
        if smoking == "Not Specified":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 0, 1, 1, 0, 0, 0]      
        if smoking == "Formerly Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 0, 1, 0, 1, 0, 0]                                                                                                       
        if smoking == "Never Smoked":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 0, 1, 0, 0, 1, 0]                                                                                                      
        if smoking == "Smokes Regularly":
            features = [int(gender), age, int(hypertension), int(heart_disease), int(ever_married), int(residence_type),
                        glucose, bmi, 0, 0, 0, 0, 1, 0, 0, 0, 1]
        
    # Load and predict with model
    model = Net2(input_size, hidden_size, num_classes)
    model.load_state_dict(torch.load('Net2w16e66(0.889).pt'))

    print(features)
    with torch.no_grad():
        model.eval()
        input_tensor = torch.tensor(features, dtype=torch.float32)
        outputs = model(input_tensor)
        print(outputs)
    
    return outputs.item()  

################## Launch ###################################

demo = gr.Interface(fn=predict_probability, 
    inputs=[gender_dropdown, gr.Slider(0, 100), hypertension_dropdown, heart_disease_dropdown, ever_married_dropdown,
           residence_type_dropdown, gr.Slider(0, 400), gr.Slider(0, 100), work_type_dropdown, smoking_dropdown]
    ,outputs="text", title="Stroke Prediction")

demo.launch()
