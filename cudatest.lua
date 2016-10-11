require 'cunn'
local cudnn = require 'cudnn'

local X = torch.rand(32, 3, 24, 24):cuda()
local Y = torch.ones(32):cuda()

local net = nn.Sequential()
net:add(cudnn.SpatialConvolution(3, 8, 5, 5))
net:add(nn.View(8*20*20))
net:add(nn.Linear(8*20*20, 10))
net:add(nn.LogSoftMax())
net:cuda()

local criterion = nn.ClassNLLCriterion():cuda()

local output = net:forward(X)
local loss = criterion:forward(output, Y)
print(loss)