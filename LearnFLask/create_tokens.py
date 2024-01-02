from itsdangerous import TimedJSONWebSignatureSerializer as Serializer

s = Serializer("secret, 30")
token = s.dumps({'used_id': 1}).decode('utf8')

print(token)