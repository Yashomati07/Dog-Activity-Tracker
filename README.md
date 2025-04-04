# Navigate to your project folder
cd your-project-folder

# Initialize Git (if not already initialized)
git init

# Add your project files
git add .

# Commit with a message
git commit -m "Initial commit with Dog Activity Tracker code and README"

# Create a new GitHub repo (replace YOUR-USERNAME and REPO-NAME)
# Visit GitHub and create a repo: https://github.com/new
# Then link your local repo to it:
git remote add origin https://github.com/YOUR-USERNAME/Dog-Activity-Tracker-project-using-ESP32.git

# Push your code to GitHub
git branch -M main
git push -u origin main
