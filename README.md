# Moving Linear Regression in C++

Linear regression (2D) is an approach to model 2 variables in form of line:

Input data:

<img src="https://render.githubusercontent.com/render/math?math=(x_{i},y_{i}), i=1...N">

Linear model:

<img src="https://render.githubusercontent.com/render/math?math=y = a %2B b x">

Liner regression estimates variables <img src="https://render.githubusercontent.com/render/math?math=a"> and <img src="https://render.githubusercontent.com/render/math?math=b"> to minimize the error:

<img src="https://render.githubusercontent.com/render/math?math=error =\frac{1}{N}  \sum_{i=1}^N(y_{i} - (a %2B b x_{i}))^{2}">

The classic derivation of the least squares estimates uses calculus to find the parameters estimates that minimize the error sum of squares:

<img src="https://render.githubusercontent.com/render/math?math=b =\frac{S_{xy}}{S_{xx}} = \frac{\sum_{i=1}^N(x_{i} - \overline{X})(y_{i} - \overline{Y})}{\sum_{i=1}^N(x_{i} - \overline{X})^{2}}">
<img src="https://render.githubusercontent.com/render/math?math=a = \overline{Y}-b \overline{X}">

where

<img src="https://render.githubusercontent.com/render/math?math=\overline{X}=\frac{1}{N} \sum_{i=1}^Nx_{i}">
<img src="https://render.githubusercontent.com/render/math?math=\overline{Y}=\frac{1}{N} \sum_{i=1}^Ny_{i}">

Using such formulas is expensive for Moving Linear Regression, so let's do the math:

<img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum_{i=1}^N(x_{i} - \overline{X})(y_{i} - \overline{Y})">
<img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum_{i=1}^Nx_{i} y_{i}-\overline{X}\sum_{i=1}^Ny_{i}-\overline{Y}\sum_{i=1}^Nx_{i}%2B N \overline{X} \overline{Y}">
<img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum_{i=1}^Nx_{i}  y_{i}-\frac{1}{N} \sum_{i=1}^Nx_{i}\sum_{i=1}^Ny_{i}-\frac{1}{N} \sum_{i=1}^Ny_{i}\sum_{i=1}^Nx_{i} %2B \frac{1}{N} \sum_{i=1}^Ny_{i}\sum_{i=1}^Nx_{i}">
<img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum_{i=1}^Nx_{i}  y_{i}-\frac{1}{N} \sum_{i=1}^Nx_{i}\sum_{i=1}^Ny_{i}">

similar for <img src="https://render.githubusercontent.com/render/math?math=S_{xx}">:

<img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum_{i=1}^N(x_{i} - \overline{X})^{2}">
<img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum_{i=1}^N(x_i^2 -2 x_i\overline{X} %2B \overline{X}^{2})">
<img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum_{i=1}^Nx_i^2 -2 \overline{X}\sum_{i=1}^Nx_i %2B N\overline{X}^{2}">
<img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum_{i=1}^Nx_i^2 -2 \frac{1}{N} \sum_{i=1}^Nx_i\sum_{i=1}^Nx_i %2B \frac{1}{N} \sum_{i=1}^Nx_i\sum_{i=1}^Nx_i">
<img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum_{i=1}^Nx_i^2 -\frac{1}{N} \sum_{i=1}^Nx_i\sum_{i=1}^Nx_i">



## Links
* https://www.amherst.edu/system/files/media/1287/SLR_Leastsquares.pdf
