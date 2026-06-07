# AIN2002-Project

## Specification and Dependencies
You can read the "requirements.txt" for information on used packages and libraries. All packages are easily installed with !pip install [package], if your machine can't finish installing after a fair amount of time, I would recommend adding -vv to pip so you can see what is causing the halt. Usually the problem is with caching, then you can add --no-cache-dir to pip which should solve the problem.

## Training Code
For each model used in the paper, there is an aptly named [model name].ipynb. All models except MLP has fixed random states and they use the whole unordered dataset which should make their results easily reproducible. MLP models have saved weight files in the form of [net type]w[hidden size]e[epoch number](public kaggle score).pt for those deemed successful, batch size is always fixed to 128 after it's affect within the range of 16-512 seen to be near non-existant aside from training time and intermediate loss.

## Evaluation code
Models are evaluated using the unlabeled test set to produce submission files, which is then submitted to the Kaggle competition (ref: https://www.kaggle.com/competitions/playground-series-s3e2/submissions) to get scores. Models are compared according to their public scores.

## Try A Demo Of The Model 
We have implemented a demo of our model using Gradio library, you can check it through [here](https://huggingface.co/spaces/Stywestern/Stroke-Prediction).
