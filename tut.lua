require 'nn'
require 'image'

itorch notebook
i=image.lena()
n=nn.SpatialConvolution(1,64,16,16)
itorch.image(n.weight)