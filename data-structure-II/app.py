from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello():
    return "Olá, Flask está funcionando no Ubuntu!"

if __name__ == "__main__":
    app.run(debug=True)