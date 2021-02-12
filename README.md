# Moving Linear Regression in C++

Linear regression (2D) is an approach to model 2 variables in form of line:

Sample data:

<img src="https://render.githubusercontent.com/render/math?math=(x_{i},y_{i}), i=1...N">

Linear model:

<img src="https://render.githubusercontent.com/render/math?math=y = a %2B b\cdot x">

Liner regression estimates variables a and b to minimize the error:

<img src="https://render.githubusercontent.com/render/math?math=error =\frac{1}{N}  \sum_{i=1}^N(y_{i} - (a %2B b\cdot x_{i}))^{2}">

...

so

b =\frac{S_{xy}}{S_{xx}} = \frac{\sum_{i=1}^N(x_{i} - \overline{X})(y_{i} - \overline{Y})}{\sum_{i=1}^N(x_{i} - \overline{X})^{2}}
a = \overline{Y}-b \cdot \overline{X}

where

\overline{X}=\frac{1}{N} \sum_{i=1}^Nx_{i}
\overline{Y}=\frac{1}{N} \sum_{i=1}^Ny_{i}

Using such formulas is expensive for Moving Linear Regression, so let's do the math:

S_{xy}=\sum_{i=1}^N(x_{i} - \overline{X})(y_{i} - \overline{Y})
      =\sum_{i=1}^Nx_{i} \cdot y_{i}-\overline{X}\sum_{i=1}^Ny_{i}-\overline{Y}\sum_{i=1}^Nx_{i}+N \overline{X} \overline{Y}
      =\sum_{i=1}^Nx_{i} \cdot y_{i}-\frac{1}{N} \sum_{i=1}^Nx_{i}\sum_{i=1}^Ny_{i}-\frac{1}{N} \sum_{i=1}^Ny_{i}\sum_{i=1}^Nx_{i}+\frac{1}{N} \sum_{i=1}^Ny_{i}\sum_{i=1}^Nx_{i}
      =\sum_{i=1}^Nx_{i} \cdot y_{i}-\frac{1}{N} \sum_{i=1}^Nx_{i}\sum_{i=1}^Ny_{i}

similar for Sxx:

S_{xx}=\sum_{i=1}^N(x_{i} - \overline{X})^{2}
      =\sum_{i=1}^N(x_i^2 -2 x_i\overline{X}+\overline{X}^{2})
      =\sum_{i=1}^Nx_i^2 -2 \overline{X}\sum_{i=1}^Nx_i+N\overline{X}^{2}
      =\sum_{i=1}^Nx_i^2 -2 \frac{1}{N} \sum_{i=1}^Nx_i\sum_{i=1}^Nx_i+\frac{1}{N} \sum_{i=1}^Nx_i\sum_{i=1}^Nx_i
      =\sum_{i=1}^Nx_i^2 -\frac{1}{N} \sum_{i=1}^Nx_i\sum_{i=1}^Nx_i

<img src="https://render.githubusercontent.com/render/math?math=e^{i \pi} = -1">
