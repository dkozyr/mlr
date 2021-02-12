# Moving Linear Regression in C++

Linear regression (2D) is an approach to model 2 variables in form of line:

Input data:

    <img src="https://render.githubusercontent.com/render/math?math=(x_{i},y_{i}),i=1...N">

Linear model:

    <img src="https://render.githubusercontent.com/render/math?math=y=a%2Bbx">

Liner regression estimates variables <img src="https://render.githubusercontent.com/render/math?math=a"> and <img src="https://render.githubusercontent.com/render/math?math=b"> to minimize the error:

    <img src="https://render.githubusercontent.com/render/math?math=error =\frac{1}{N}\sum(y_{i}-(a%2Bbx_{i}))^{2}">

The classic derivation of the least squares estimates uses calculus to find the parameters estimates that minimize the error sum of squares, so:

    <img src="https://render.githubusercontent.com/render/math?math=b =\frac{S_{xy}}{S_{xx}} = \frac{\sum (x_{i} - \overline{X})(y_{i} - \overline{Y})}{\sum (x_{i} - \overline{X})^{2}}">
    <img src="https://render.githubusercontent.com/render/math?math=a = \overline{Y}-b \overline{X}">

where:

    <img src="https://render.githubusercontent.com/render/math?math=\overline{X}=\frac{1}{N} \sum x_{i}">
    <img src="https://render.githubusercontent.com/render/math?math=\overline{Y}=\frac{1}{N} \sum y_{i}">

Using such formulas is expensive for Moving Linear Regression, so let's do the math:

    <img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum (x_{i} - \overline{X})(y_{i} - \overline{Y})">
    <img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum x_{i} y_{i}-\overline{X} \sum y_{i}-\overline{Y} \sum x_{i}%2B N \overline{X} \overline{Y}">
    <img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum x_{i}  y_{i}-\frac{1}{N} \sum x_{i} \sum y_{i}-\frac{1}{N} \sum y_{i} \sum x_{i} %2B \frac{1}{N} \sum y_{i} \sum x_{i}">
    <img src="https://render.githubusercontent.com/render/math?math=S_{xy}=\sum x_{i}  y_{i}-\frac{1}{N} \sum x_{i} \sum y_{i}">

similar for <img src="https://render.githubusercontent.com/render/math?math=S_{xx}">:

    <img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum (x_{i} - \overline{X})^{2}">
    <img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum (x_i^2 -2 x_i\overline{X} %2B \overline{X}^{2})">
    <img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum x_i^2 -2 \overline{X}\sum x_i %2B N\overline{X}^{2}">
    <img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum x_i^2 -2 \frac{1}{N} \sum x_i\sum x_i %2B \frac{1}{N} \sum x_i\sum x_i">
    <img src="https://render.githubusercontent.com/render/math?math=S_{xx}=\sum x_i^2 -\frac{1}{N} (\sum x_i)^2">

Then multiply <img src="https://render.githubusercontent.com/render/math?math=S_{xy}"> and <img src="https://render.githubusercontent.com/render/math?math=S_{xx}"> by <img src="https://render.githubusercontent.com/render/math?math=N"> we get formulas in form of sums:

    <img src="https://render.githubusercontent.com/render/math?math=b=\frac{S_{xy}}{S_{xx}}=
\frac{N\sum x_{i}y_{i}-\sum x_{i} \sum y_{i}}{N\sum x_i^2 -(\sum x_i)^2}">
    <img src="https://render.githubusercontent.com/render/math?math=a = \overline{Y}-b \overline{X}">


### Useful Links
* https://www.amherst.edu/system/files/media/1287/SLR_Leastsquares.pdf
