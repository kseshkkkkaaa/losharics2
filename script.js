const btnNo = document.getElementById('btn-no');
const btnGroup = document.querySelector('.btn-group');
function moveButton() {
    const flightRange = 450; 
    const x = (Math.random() * 2 - 1) * flightRange;
    const y = (Math.random() * 2 - 1) * flightRange;
    btnNo.style.right = 'auto';
    btnNo.style.left = `calc(50% + ${x}px)`; 
    btnNo.style.top = `${y}px`;
}
btnNo.addEventListener('mouseenter', moveButton);
btnNo.addEventListener('touchstart', (e) => {
    e.preventDefault();
    moveButton();
});