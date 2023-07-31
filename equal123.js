let a = {
  n: 1,
  valueOf() {
    return this.n++;
  }
};
if (a == 1 && a == 2 && a == 3) {
  console.log("true");
}
