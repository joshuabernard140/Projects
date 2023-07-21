using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LogicScript : MonoBehaviour
{
    public int playerScore;
    public Text scoreText;
    public GameObject gameOverScreen;

    [ContextMenu("Increase Score")]
    public void addScore() {
        playerScore += 1;
        scoreText.text = playerScore.ToString();
    }

    public void gameOver() {
        gameOverScreen.SetActive(true);
    }
}
