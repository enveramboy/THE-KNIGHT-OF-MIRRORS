window.addEventListener('load', onLoad);

function makeElement(type, id, c, parent) {
  let ret = document.createElement(type);
  if (id) ret.id = id;
  if (c) ret.className = c;
  parent.appendChild(ret);
  return ret;
}

let root;
function onLoad(event) {
  root = document.getElementById("root");
  loadTitle(root);
}

function loadTitle(r) {
  r.innerHTML = '';
  document.body.style = 'margin: 0px; background: url("media/kofTitle.gif") no-repeat center center fixed; -webkit-background-size: cover; -moz-background-size: cover; -o-background-size: cover; background-size: cover;';
  let t1 = makeElement("p", "t1", "fadeIn", r);
  t1.innerText = "THE GLORIOUS METAL GEAR";
  let t2 = makeElement("p", "t2", "fadeIn", r);
  t2.innerText = "THE KNIGHT";
  let t3 = makeElement("p", "t3", "fadeIn", r);
  t3.innerText = "OF MIRRORS";
  let kofGif = makeElement("img", "kofGif", null, r);
  kofGif.src = "media/kof.gif";
  let startNoti = makeElement("p", "startNoti", null, r);
  startNoti.innerText = "PRESS ANY KEY TO START";
  setTimeout(() => { 
    startNoti.style = 'visibility: visible;';
    startNoti.className = "fadeIn"; 
    kofGif.style = 'visibility: visible;';
    kofGif.className = "fadeInKof"; 
  }, 3000);
  setTimeout(() => {
    startNoti.className = 'blink'; 
    document.body.addEventListener("keydown", () => { loadInfo(r); });
  }, 6000);
}

function loadInfo(r) {
  r.innerHTML = '';
  document.body.style = 'margin: 0px; background-color: black;';
  let loadDiv = makeElement("div", "loadDiv", null, r);
  let loadP = makeElement("p", "loadP", null, loadDiv);
  loadP.innerText = "SELECT A VIEW OPTION";
  let btnDiv = makeElement("div", "btnDiv", null, loadDiv);
  let controls = makeElement("button", "controlsBtn", null, btnDiv);
  controls.innerText = "CONTROLS";
  controls.addEventListener("click", () => { loadControls(r); });
  let about = makeElement("button", "aboutBtn", null, btnDiv);
  about.innerText = "ABOUT";
  about.addEventListener("click", () => { loadAbout(r); });
  let video = makeElement("button", "videoBtn", null, btnDiv);
  video.innerText = "VIDEO";
  video.addEventListener("click", () => { loadVideo(r); });
  let returnNoti = makeElement("p", "returnNoti", "blink", loadDiv);
  returnNoti.innerText = "PRESS ANY KEY TO RETURN";
  document.body.addEventListener("keydown", () => { loadTitle(r); });
}

function loadControls(r) {
  r.innerHTML = '';
  let controls = makeElement("img", "controls", null, r);
  controls.src = "media/controls.png";
  let backNoti = makeElement("p", "backNoti", "blink", r);
  backNoti.innerText = "CONFIRM";
  document.body.addEventListener("keydown", () => { loadInfo(r); });
}

function loadAbout(r) {
  r.innerHTML = '';
  let backNoti = makeElement("p", "aboutBackNoti", "blink", r);
  backNoti.innerText = "CONFIRM";
  document.body.addEventListener("keydown", () => { loadInfo(r); });
  let slide = makeElement("img", "slide", "slideImg", r);
  slide.src = "media/slide1.gif";
  let text = makeElement("p", "text", null, r);
  animateMsg(["THE KNIGHT OF MIRRORS IS A QUADRUPED MACHINE THAT IS CONTROLLABLE VIA A PLAYSTATION 3 CONTROLLER UTILIZING THE ESP32'S BLUETOOTH MODULE.", "IT TAKES INSPIRATION FROM THE KAME ROBOT."]);
  setTimeout(() => {
    slide.src = "media/slide2.gif";
    animateMsg(["IT UTILIZES EIGHT MG90S SERVOS FOR LOCOMOTION", "LOCOMOTION IS DIVIDED INTO FOUR PHASES: ", "A RAISE PHASE, IN WHICH SPECIFIED LEGS RISE AND MOVE HALFWAY TO THEIR DESIRED POSITION FOR DESIRED THRUST POWER.", "A LOWER PHASE, IN WHICH THE LEGS ARE LOWERED AND POSITIONED TO THEIR FINAL POSITION FOR DESIRED THRUST POWER.", "AND A THRUST PHASE, IN WHICH THE LEGS NOW FULLY IN CONTACT WITH THE GROUND, SHIFT TO THEIR ORIGINAL POSITION.", "THUS THRUSTING THE MACHINE TOWARDS A CERTAIN DIRECTION.", "THIS THRUST PHASE TRANSLATES ALL THE PREVIOUS PHASES INTO PROPULSION."]);
  }, 12850);
  setTimeout(() => {
    slide.src = "media/slide3.gif";
    animateMsg(["LEGS ARE GROUPED INTO DIAGONAL PAIRS.", "THUS AT MOST ONLY TWO LEGS ARE RAISED OFF THE GROUND AT ONCE.", "THIS ALLOWS FOR THE MACHINE TO MAINTAIN STABILITY EVEN DURING THE RAISE PHASE.", "THESE DIAGONAL PAIRINGS ALTERNATE CYCLING THROUGH ALL OF THESE PHASES.", "THUS THE KNIGHT OF MIRRORS MOVES!"]);
  }, 48800);
  setTimeout(() => {
    slide.src = "media/slide4.gif";
    animateMsg(["FORWARD MOTION POSITIONS THE LEGS FORWARD, THUS ON THE THRUST PHASE THE LEGS MOVE BACKWARD PUSHING THE MACHINE FORWARDS.", "INTUITIVELY BACKWARDS MOVEMENT IS THE REVERSE OF FORWARDS MOVEMENT.", "LEGS ARE ORIENTED BACK THEN THRUST FORWARD."]);
  }, 69750);
  setTimeout(() => {
    slide.src = "media/slide5.gif";
    animateMsg(["LEFT TURNING HAS THE LEFT LEG (WITH RESPECT TO THE FRONT OF THE MACHINE) AND ITS PAIR POSITIONING TOWARDS EACH OTHER.", "THE OTHER PAIR ORIENT AWAY FROM EACH OTHER.", "THUS ON THE THRUST PHASE THE MACHINE TURNS LEFT.", "RIGHT TURNING IS THE REVERSE OF SUCH."]);
  }, 86250);
  setTimeout(() => {
    slide.src = "media/slide6.png";
    animateMsg(["THE CIRCUIT SCHEMATIC IS AS FOLLOWS.", "ITS INTELLIGENCE RESIDES THROUGH THE ESP32 MICRO-CONTROLLER.", "IT UTILIZES A PCA9685 TO DRIVE THE SERVOS.", "THE ENTIRE CIRCUIT IS DRIVEN BY A 7.4V 50C 450MAH BATTERY, WHICH IS STEPPED DOWN TO 6V BY A MINI 360 BUCK CONVERTER."]);
  }, 104500);
  function animateSentence(s) {
    text.innerText = "";
    let buffer = "";
    s.split("").forEach((l, i) => {
      setTimeout(() => { 
        buffer = buffer.concat(l);
        text.innerText = buffer;
       }, i*50);
    });
  }

  function animateMsg(msg) {
    let timeout = 0;
    msg.forEach((s) => {
      setTimeout(() => { animateSentence(s); }, timeout);
      timeout += s.length*75 + 1000;
    });
  }
}

function loadVideo(r) {
  r.innerHTML = '';
  let backNoti = makeElement("p", "aboutBackNoti", "blink", r);
  backNoti.innerText = "CONFIRM";
  document.body.addEventListener("keydown", () => { loadInfo(r); });
  let slide = makeElement("div", "slide", "slideImg", r);
  slide.innerHTML = '<iframe width="100%" height="100%" src="https://www.youtube.com/embed/m0jUERGDB80" title="THE KNIGHT OF MIRRORS" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>';
  let text = makeElement("p", "text", null, r);
  animateMsg(["HERE IS A PERFORMANCE VIDEO OF THE KNIGHT OF MIRRORS.", "PLEASE HAVE A LOOK."]);

  function animateSentence(s) {
    text.innerText = "";
    let buffer = "";
    s.split("").forEach((l, i) => {
      setTimeout(() => { 
        buffer = buffer.concat(l);
        text.innerText = buffer;
       }, i*50);
    });
  }

  function animateMsg(msg) {
    let timeout = 0;
    msg.forEach((s) => {
      setTimeout(() => { animateSentence(s); }, timeout);
      timeout += s.length*50 + 1000;
    });
  }
}