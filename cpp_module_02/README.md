### Input:  
        _nbFractionalBits = 8;  
        (1 << _nbFractionalBits) = 256 = 2 to the power of 8

### `int` to `fixed-point`
    _value = nb * (1 << _nbFractionalBits)
         
### `float`to `fixed-point`
    _value = rountf(nb * (1 << _nbFractionalBits))

### `fixed-point` to `int`
    nb = _value / (1 << _nbFractionalBits)

### `fixed-point` to `float`
    nb = (float)_value / (1 << _nbFractionalBits)
